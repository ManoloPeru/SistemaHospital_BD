#include "EquipoMedicoController.h"

using namespace SistemaHospitalController;
using namespace System::IO; //Para leer archivos

EquipoMedicoController::EquipoMedicoController() {

}

List<EquipoMedico^>^ EquipoMedicoController::listarEquipoMedico() {
    List<EquipoMedico^>^ listaEquipoMedicos = gcnew List<EquipoMedico^>();
    array<String^>^ lineasArchivo = File::ReadAllLines("EquiposMedicos.txt");
    String^ separadores = ";";
    for each (String ^ linea in lineasArchivo) {
        /*Voy a separar los datos de una linea en un arreglo de string*/
        array<String^>^ datos = linea->Split(separadores->ToCharArray());
        //Clase Persona
        int idEquipoMedico = Convert::ToInt32(datos[0]);
        String^ nombre = datos[1];
        String^ disponible = datos[2];
        bool disponibilidad = true;
        if (disponible->Equals("No Disponible")) {
            disponibilidad = false;
        }

        // Crear objeto EquipoMedico y añadir a la lista
        EquipoMedico^ equipoMedico = gcnew EquipoMedico();
        // Asignar propiedades de Persona
        equipoMedico->setIdEquipo(idEquipoMedico);
        equipoMedico->setNombre(nombre);
        equipoMedico->setDisponibilidad(disponibilidad);
        listaEquipoMedicos->Add(equipoMedico);
    }
    return listaEquipoMedicos;
}

List<ReporteEquipoMedico^>^ EquipoMedicoController::contarCantidadEquipos() {
	List<ReporteEquipoMedico^>^ listarCantidadEquipos = gcnew List<ReporteEquipoMedico^>();
    //Disponible
    ReporteEquipoMedico^ objReporteEquipo1 = gcnew ReporteEquipoMedico();
    objReporteEquipo1->setEquipo("Disponible");
    objReporteEquipo1->setCantidad(0);
    listarCantidadEquipos->Add(objReporteEquipo1);
    //No Disponible
    ReporteEquipoMedico^ objReporteEquipo2 = gcnew ReporteEquipoMedico();
    objReporteEquipo2->setEquipo("No Disponible");
    objReporteEquipo2->setCantidad(0);
    listarCantidadEquipos->Add(objReporteEquipo2);

    List<EquipoMedico^>^ listaEquipos = listarEquipoMedico();
    for each (EquipoMedico^ equipo in listaEquipos) {
        if (equipo->getDisponibilidad() == true) {
            //Disponible
            listarCantidadEquipos[0]->setCantidad(listarCantidadEquipos[0]->getCantidad() + 1);
        }
        else {
            //No Disponible
            listarCantidadEquipos[1]->setCantidad(listarCantidadEquipos[1]->getCantidad() + 1);
        }
    }
    return listarCantidadEquipos;
}