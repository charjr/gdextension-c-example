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
    api.get_variant_from_type_constructor = (GDExtensionInterfaceGetVariantFromTypeConstructor)p_get_proc_address("get_variant_from_type_constructor");
    api.get_variant_to_type_constructor = (GDExtensionInterfaceGetVariantToTypeConstructor)p_get_proc_address("get_variant_to_type_constructor");
    api.variant_get_type = (GDExtensionInterfaceVariantGetType)p_get_proc_address("variant_get_type");

    // Constructors.
    constructors.string_name_new_with_latin1_chars = (GDExtensionInterfaceStringNameNewWithLatin1Chars)p_get_proc_address("string_name_new_with_latin1_chars");
    constructors.variant_from_float_constructor = api.get_variant_from_type_constructor(GDEXTENSION_VARIANT_TYPE_FLOAT);
    constructors.float_from_variant_constructor = api.get_variant_to_type_constructor(GDEXTENSION_VARIANT_TYPE_FLOAT);

    // Destructors.
    destructors.string_name_destructor = variant_get_ptr_destructor(GDEXTENSION_VARIANT_TYPE_STRING_NAME);
}

void call_0_args_ret_float(void *method_userdata, GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error)
{
    // Check argument count.
    if (p_argument_count != 0)
    {
        r_error->error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
        r_error->expected = 0;
        return;
    }

    // Call the function.
    double (*function)(void *) = method_userdata;
    double result = function(p_instance);
    // Set resulting Variant.
    constructors.variant_from_float_constructor(r_return, &result);
}

void call_1_float_arg_no_ret(void *method_userdata, GDExtensionClassInstancePtr p_instance, const GDExtensionConstVariantPtr *p_args, GDExtensionInt p_argument_count, GDExtensionVariantPtr r_return, GDExtensionCallError *r_error)
{
    // Check argument count.
    if (p_argument_count < 1)
    {
        r_error->error = GDEXTENSION_CALL_ERROR_TOO_FEW_ARGUMENTS;
        r_error->expected = 1;
        return;
    }
    else if (p_argument_count > 1)
    {
        r_error->error = GDEXTENSION_CALL_ERROR_TOO_MANY_ARGUMENTS;
        r_error->expected = 1;
        return;
    }

    // Check the argument type.
    GDExtensionVariantType type = api.variant_get_type(p_args[0]);
    if (type != GDEXTENSION_VARIANT_TYPE_FLOAT)
    {
        r_error->error = GDEXTENSION_CALL_ERROR_INVALID_ARGUMENT;
        r_error->expected = GDEXTENSION_VARIANT_TYPE_FLOAT;
        r_error->argument = 0;
        return;
    }

    // Extract the argument.
    double arg1;
    constructors.float_from_variant_constructor(&arg1, (GDExtensionVariantPtr)p_args[0]);

    // Call the function.
    void (*function)(void *, double) = method_userdata;
    function(p_instance, arg1);
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
