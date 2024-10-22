#pragma once
#include "Persona.h"
#include "Especialidad.h"
#include "Paciente.h"

namespace SistemaHospitalModel {
    
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Medico : public Persona {
    private:
        int idMedico;
        String^ numeroColegioMedico;
        List<String^>^ certificaciones;
        List<Especialidad^>^ especialidades;
        List<int>^ idCitasAsignadas; //Lista de idCitas
        List<Paciente^>^ pacientesAsociados;

    public:
        // Constructor vacío
        Medico();

        // Constructor con parámetros
        Medico(int idMedico, String^ numeroColegioMedico, List<String^>^ certificaciones, List<Especialidad^>^ especialidades, List<int>^ idCitasAsignadas, List<Paciente^>^ pacientesAsociados);

        // Métodos GET
        int getIdMedico();
        String^ getNumeroColegioMedico();
        List<String^>^ getCertificaciones();
        List<Especialidad^>^ getEspecialidades();
        List<int>^ getidCitasAsignadas();
        List<Paciente^>^ getPacientesAsociados();

        // Métodos SET
        void setIdMedico(int idMedico);
        void setNumeroColegioMedico(String^ numeroColegioMedico);
        void setCertificaciones(List<String^>^ certificaciones);
        void setEspecialidades(List<Especialidad^>^ especialidades);
        void setidCitasAsignadas(List<int>^ idCitasAsignadas);
        void setPacientesAsociados(List<Paciente^>^ pacientesAsociados);
    };
}
