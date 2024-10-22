#pragma once
#include "Tratamiento.h"

namespace SistemaHospitalModel {
    
    using namespace System;
    using namespace System::Collections::Generic; // Para usar List en C++/CLI

    public ref class HistorialMedico {
    private:
        List<Tratamiento^>^ tratamientos;

    public:
        // Constructor vacío
        HistorialMedico();

        // Constructor con parámetros
        HistorialMedico(List<Tratamiento^>^ tratamientos);

        // Métodos GET
        List<Tratamiento^>^ getTratamientos();

        // Métodos SET
        void setTratamientos(List<Tratamiento^>^ tratamientos);
    };
}
