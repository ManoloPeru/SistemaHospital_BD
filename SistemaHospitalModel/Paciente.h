#pragma once
#include "Persona.h"
#include "HistorialMedico.h"

namespace SistemaHospitalModel {

    using namespace System;
    using namespace System::Collections::Generic; // Para usar List en C++/CLI

    public ref class Paciente : public Persona {
    private:
        int idPaciente;
        String^ numeroSeguroSocial;
        String^ grupoSanguíneo;
        List<String^>^ alergias;
        HistorialMedico^ historialMedico; // Referencia a la clase HistorialMedico
        String^ contactoEmergencia;
        List<String^>^ diagnosticos;

    public:
        // Constructor vacío
        Paciente();

        // Constructor con parámetros
        Paciente(int idPaciente, String^ numeroSeguroSocial, String^ grupoSanguíneo, List<String^>^ alergias, HistorialMedico^ historialMedico, String^ contactoEmergencia, List<String^>^ diagnosticos);

        // Métodos GET
        int getIdPaciente();
        String^ getNumeroSeguroSocial();
        String^ getGrupoSanguíneo();
        List<String^>^ getAlergias();
        HistorialMedico^ getHistorialMedico();
        String^ getContactoEmergencia();
        List<String^>^ getDiagnosticos();

        // Métodos SET
        void setIdPaciente(int idPaciente);
        void setNumeroSeguroSocial(String^ numeroSeguroSocial);
        void setGrupoSanguíneo(String^ grupoSanguíneo);
        void setAlergias(List<String^>^ alergias);
        void setHistorialMedico(HistorialMedico^ historialMedico);
        void setContactoEmergencia(String^ contactoEmergencia);
        void setDiagnosticos(List<String^>^ diagnosticos);
    };
}
