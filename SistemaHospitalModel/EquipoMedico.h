#pragma once
#include <string>

namespace SistemaHospitalModel {
    
    using namespace System;

    public ref class EquipoMedico {
    private:
        int idEquipo;
        String^ nombre;
        bool disponibilidad;

    public:
        // Constructor vacío
        EquipoMedico();

        // Constructor con parámetros
        EquipoMedico(int idEquipo, String^ nombre, bool disponibilidad);

        // Métodos GET
        int getIdEquipo();
        String^ getNombre();
        bool getDisponibilidad();

        // Métodos SET
        void setIdEquipo(int idEquipo);
        void setNombre(String^ nombre);
        void setDisponibilidad(bool disponibilidad);
    };

    public ref class ReporteEquipoMedico {
    private:
        String^ equipo;
        int cantidad;

    public:
        // Constructor vacío
        ReporteEquipoMedico();

        // Constructor con parámetros
        ReporteEquipoMedico(String^ equipo, int cantidad);

        // Métodos GET
        String^ getEquipo();
        int getCantidad();

        // Métodos SET
        void setEquipo(String^ equipo);
        void setCantidad(int cantidad);
    };
}
