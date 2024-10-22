#include "HistorialMedico.h"

namespace SistemaHospitalModel {

    // Constructor vacío
    HistorialMedico::HistorialMedico() {
        this->tratamientos = gcnew List<Tratamiento^>();
    }

    // Constructor con parámetros
    HistorialMedico::HistorialMedico(List<Tratamiento^>^ tratamientos) {
        this->tratamientos = tratamientos;
    }

    // Métodos GET
    List<Tratamiento^>^ HistorialMedico::getTratamientos() {
        return this->tratamientos;
    }

    // Métodos SET
    void HistorialMedico::setTratamientos(List<Tratamiento^>^ tratamientos) {
        this->tratamientos = tratamientos;
    }
}
