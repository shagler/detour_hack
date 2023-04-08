#ifndef _VMTHOOK_H_
#define _VMTHOOK_H_

namespace vmt {
	struct Hook_Manager {
		PDWORD* class_base;
		PDWORD  new_virtual_method_table;
		PDWORD  old_virtual_method_table;
		DWORD   virtual_method_table_size;

		void initalize(PDWORD* class_base) {
			// Setup the standard variables. 
			this->class_base                = class_base;
			this->old_virtual_method_table  = *class_base;
			this->virtual_method_table_size = this->get_virtual_method_count(*class_base);

			// Allocate the new virtual method table and copy over the contents of the old virtual method table.
			this->new_virtual_method_table  = new DWORD[this->virtual_method_table_size];
			memcpy(this->new_virtual_method_table, this->old_virtual_method_table, sizeof(DWORD) * this->virtual_method_table_size);

			// Set the class base's table to be the new virtual method table. 
			*this->class_base = this->new_virtual_method_table;
		}

		void hook_base() {
			if (this->class_base) {
				*this->class_base = this->old_virtual_method_table;
			}
		}

		void unhook_base() {
			if (this->class_base) {
				*this->class_base = this->new_virtual_method_table;
			}
		}

		DWORD get_method_address(int index) {
			// Validate that the index is within range and that the old virtual table exists.
			if (index >= 0 && index <= (int)this->virtual_method_table_size && this->old_virtual_method_table) {
				// Return the function/method add the index within the old virtual method table. 
				return this->old_virtual_method_table[index];
			}
			return 0;
		}

		DWORD hook_method(DWORD new_function, unsigned int index) {
			// Validate that the index is within range and the new virutal method table and old virtual method table are valid. 
			if (index >= 0 && this->new_virtual_method_table && this->old_virtual_method_table && index <= this->virtual_method_table_size) {
				// Set the new virtual method table to the new function.
				this->new_virtual_method_table[index] = new_function;

				// Return the function at the index within the old virtual method table.
				return this->old_virtual_method_table[index];
			}
			return 0;
		}

		DWORD get_virtual_method_count(PDWORD virtual_method_table) {
			DWORD result = 0;

			// Iterate through the entire virtual method table.
			while (virtual_method_table[result]) {
				// If we reached an invalid memory address.
				if (IsBadCodePtr((FARPROC)virtual_method_table[result])) {
					break;
				}

				// Increment the virtual method count.
				result++;
			}

			return result;
		}
	};
}

#endif /* _VMTHOOK_H_ */