#pragma once

#include "gdextension_interface.h"

#include "defs.h"

// Struct to hold the node data.
typedef struct
{
    // Public properties.
    double amplitude;
    double speed;
    // Metadata.
    GDExtensionObjectPtr object; // Stores the underlying Godot object.
} GDExample;

// Constructor for the node.
void gdexample_class_constructor(GDExample *self);

// Destructor for the node.
void gdexample_class_destructor(GDExample *self);

// Properties.
void gdexample_class_set_amplitude(GDExample *self, double amplitude);
double gdexample_class_get_amplitude(const GDExample *self);
void gdexample_class_set_speed(GDExample *self, double speed);
double gdexample_class_get_speed(const GDExample *self);

// Bindings.
void gdexample_class_bind_methods();
GDExtensionObjectPtr gdexample_class_create_instance(void *p_class_userdata);
void gdexample_class_free_instance(void *p_class_userdata, GDExtensionClassInstancePtr p_instance);
