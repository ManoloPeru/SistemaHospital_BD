#pragma once
#include <string>

namespace SistemaHospitalModel {
    
    using namespace System;

    public ref class Especialidad {
    private:
        int idEspecialidad;
        String^ nombre;
        String^ descripcion;

    public:
        // Constructor vacío
        Especialidad();

        // Constructor con parámetros
        Especialidad(int idEspecialidad, String^ nombre, String^ descripcion);

        // Métodos GET
        int getIdEspecialidad();
        String^ getNombre();
        String^ getDescripcion();

        // Métodos SET
        void setIdEspecialidad(int idEspecialidad);
        void setNombre(String^ nombre);
        void setDescripcion(String^ descripcion);
    };
}
