#include "api.h"

GDExtensionClassLibraryPtr class_library = NULL;

void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address)
{
    // Get helper functions first.
    GDExtensionInterfaceVariantGetPtrDestructor variant_get_ptr_destructor = (GDExtensionInterfaceVariantGetPtrDestructor)p_get_proc_address("variant_get_ptr_destructor");

    // API.
    api.classdb_register_extension_class2 = p_get_proc_address("classdb_register_extension_class2");

    // Constructors.
    constructors.string_name_new_with_latin1_chars = p_get_proc_address("string_name_new_with_latin1_chars");

    // Destructors.
    destructors.string_name_destructor = variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
}
