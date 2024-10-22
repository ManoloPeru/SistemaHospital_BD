#pragma once
#include "EquipoMedico.h"

namespace SistemaHospitalModel {
    
    using namespace System;
    using namespace System::Collections::Generic; // Para usar List en C++/CLI

    public ref class Procedimiento {
    private:
        int idProcedimiento;
        String^ nombre;
        String^ tipo;
        List<EquipoMedico^>^ equiposRequeridos;

    public:
        // Constructor vacío
        Procedimiento();

        // Constructor con parámetros
        Procedimiento(int idProcedimiento, String^ nombre, String^ tipo, List<EquipoMedico^>^ equiposRequeridos);

        // Métodos GET
        int getIdProcedimiento();
        String^ getNombre();
        String^ getTipo();
        List<EquipoMedico^>^ getEquiposRequeridos();

        // Métodos SET
        void setIdProcedimiento(int idProcedimiento);
        void setNombre(String^ nombre);
        void setTipo(String^ tipo);
        void setEquiposRequeridos(List<EquipoMedico^>^ equiposRequeridos);
    };
}
