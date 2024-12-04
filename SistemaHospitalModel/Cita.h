#pragma once
#include "Paciente.h"
#include "Medico.h"
#include "Tratamiento.h"

namespace SistemaHospitalModel {
    
    using namespace System;

    public ref class Cita {
    private:
        int idCita;
        Paciente^ paciente; // Referencia a un objeto Paciente
        Medico^ medico;     // Referencia a un objeto Medico
        int fecha;          // Formato YYYYMMDD -> 20241024
        String^ hora;       // Formato HH:MM -> 14:15
        String^ proposito;
        String^ resultado;
        Tratamiento^ tratamientoProgramado; // Referencia a un objeto Tratamiento

        //Atributos adicionales para las consultas o reportes
        String^ nombrePaciente;
        String^ nombreMedico;

    public:
        // Constructor vac�o
        Cita();

        // Constructor con par�metros: 
        Cita(int idCita, Paciente^ paciente, Medico^ medico, int fecha, String^ hora, String^ proposito, String^ resultado, Tratamiento^ tratamientoProgramado);

        // M�todos GET
        int getIdCita();
        Paciente^ getPaciente();
        Medico^ getMedico();
        int getFecha();
        String^ getHora();
        String^ getProposito();
        String^ getResultado();
        Tratamiento^ getTratamientoProgramado();

        // M�todos SET
        void setIdCita(int idCita);
        void setPaciente(Paciente^ paciente);
        void setMedico(Medico^ medico);
        void setFecha(int fecha);
        void setHora(String^ hora);
        void setProposito(String^ proposito);
        void setResultado(String^ resultado);
        void setTratamientoProgramado(Tratamiento^ tratamientoProgramado);

        //Atributos adicionales
        String^ getNombrePaciente();
        String^ getNombreMedico();
        void setNombrePaciente(String^ nombrePaciente);
        void setNombreMedico(String^ nombreMedico);
    };

    public ref class ReporteCita {
    private:
        String^ fecha;
        int cantidad;

    public:
        // Constructor vac�o
        ReporteCita();

        // Constructor con par�metros
        ReporteCita(String^ fecha, int cantidad);

        // M�todos GET
        String^ getFecha();
        int getCantidad();

        // M�todos SET
        void setFecha(String^ fecha);
        void setCantidad(int cantidad);
    };
}
