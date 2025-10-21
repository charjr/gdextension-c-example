#include "api.h"

GDExtensionClassLibraryPtr class_library = NULL;

struct Constructors constructors;
struct Destructors destructors;
struct API api;

void load_api(GDExtensionInterfaceGetProcAddress p_get_proc_address)
{
    // Get helper functions first.
    GDExtensionInterfaceVariantGetPtrDestructor variant_get_ptr_destructor = (GDExtensionInterfaceVariantGetPtrDestructor)p_get_proc_address("variant_get_ptr_destructor");

    // API.
    api.classdb_register_extension_class2 = (GDExtensionInterfaceClassdbRegisterExtensionClass2)p_get_proc_address("classdb_register_extension_class2");
    api.classdb_construct_object = (GDExtensionInterfaceClassdbConstructObject)p_get_proc_address("classdb_construct_object");
    api.object_set_instance = p_get_proc_address("object_set_instance");
    api.object_set_instance_binding = p_get_proc_address("object_set_instance_binding");
    api.mem_alloc = (GDExtensionInterfaceMemAlloc)p_get_proc_address("mem_alloc");
    api.mem_free = (GDExtensionInterfaceMemFree)p_get_proc_address("mem_free");

    // Constructors.
    constructors.string_name_new_with_latin1_chars = (GDExtensionInterfaceStringNameNewWithLatin1Chars)p_get_proc_address("string_name_new_with_latin1_chars");

    // Destructors.
    destructors.string_name_destructor = variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
}

void ptrcall_0_args_ret_float(void *method_userdata, GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret)
{
    // Call the function.
    double (*function)(void *) = method_userdata;
    *((double *)r_ret) = function(p_instance);
}

void ptrcall_1_float_arg_no_ret(void *method_userdata, GDExtensionClassInstancePtr p_instance, const GDExtensionConstTypePtr *p_args, GDExtensionTypePtr r_ret)
{
    // Call the function.
    void (*function)(void *, double) = method_userdata;
    function(p_instance, *((double *)p_args[0]));
}
