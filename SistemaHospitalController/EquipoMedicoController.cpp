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
        String^ disponibilidad = datos[2];

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
        if (equipo->getDisponibilidad()->Equals("Disponible")) {
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


List< EquipoMedico^>^ EquipoMedicoController::listarEquiposMedicosxNombre(String^ nombre) {
	List<EquipoMedico^>^ listaEquipos = gcnew List<EquipoMedico^>();
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();
	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
	objSentencia->CommandText = "select id, nombre, disponibilidad from EquipoMedico where nombre like '%" + nombre + "%' ";
	/*Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT*/
	/*Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {

		int idEquipo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		String^ disponibilidad = safe_cast<String^>(objData[2]);
		EquipoMedico^ objEquipoMedico = gcnew EquipoMedico(idEquipo, nombre, disponibilidad);
		listaEquipos->Add(objEquipoMedico);
	}
	objData->Close();
	cerrarConexion();
	return listaEquipos;
}

List< EquipoMedico^>^ EquipoMedicoController::listarEquiposMedicosAll() {
	List<EquipoMedico^>^ listaEquipos = gcnew List<EquipoMedico^>();
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();
	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
	objSentencia->CommandText = "select id, nombre, disponibilidad from EquipoMedico";
	/*Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT*/
	/*Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int idEquipo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		String^ disponibilidad = safe_cast<String^>(objData[2]);
		EquipoMedico^ objEquipoMedico = gcnew EquipoMedico(idEquipo, nombre, disponibilidad);
		listaEquipos->Add(objEquipoMedico);
	}
	objData->Close();
	cerrarConexion();
	return listaEquipos;
}

EquipoMedico^ EquipoMedicoController::buscarEquipoMedicoById(int idEquipo) {
	EquipoMedico^ objEquipoMedico = nullptr;
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();
	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
	objSentencia->CommandText = "select id, nombre, disponibilidad from EquipoMedico where id = " + idEquipo.ToString();
	/*Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT*/
	/*Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int idEquipo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		String^ disponibilidad = safe_cast<String^>(objData[2]);
		objEquipoMedico = gcnew EquipoMedico(idEquipo, nombre, disponibilidad);
	}
	objData->Close();
	cerrarConexion();
	return objEquipoMedico;
}
EquipoMedico^ EquipoMedicoController::buscarEquipoMedicoByNombre(String^ nombre) {
	EquipoMedico^ objEquipoMedico = nullptr;
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();
	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
	objSentencia->CommandText = "select id, nombre, disponibilidad from EquipoMedico where nombre = " + nombre;
	/*Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT*/
	/*Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader*/
	SqlDataReader^ objData = objSentencia->ExecuteReader();
	while (objData->Read()) {
		int idEquipo = safe_cast<int>(objData[0]);
		String^ nombre = safe_cast<String^>(objData[1]);
		String^ disponibilidad = safe_cast<String^>(objData[2]);
		objEquipoMedico = gcnew EquipoMedico(idEquipo, nombre, disponibilidad);
	}
	objData->Close();
	cerrarConexion();
	return objEquipoMedico;
}
void  EquipoMedicoController::registrarEquipoMedico(String^ nombre, String^ disponibilidad) {
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();

	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();

	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/

	objSentencia->CommandText = "insert into EquipoMedico(nombre,disponibilidad) values ('" + nombre + "','" + disponibilidad + "')";
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void  EquipoMedicoController::eliminarEquipoMedico(int idEquipo) {
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();
	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
	objSentencia->CommandText = "delete from EquipoMedico where id=" + idEquipo.ToString();
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}

void  EquipoMedicoController::actualizarEquipoMedico(int idEquipo, String^ nombre, String^ disponibilidad) {
	abrirConexion();
	/*SqlCommand nos permite crear un objeto a trav�s del cual voy a definir una sentencia SQL*/
	SqlCommand^ objSentencia = gcnew SqlCommand();
	/*Aqui estoy indicando que mi sentencia se va a ejecutar en esa conexion de base de datos*/
	objSentencia->Connection = this->getObjConexion();
	/*Aqui voy a definir la sentencia SQL que voy a ejecutar*/
	objSentencia->CommandText = "update EquipoMedico set nombre='" + nombre + "', disponibilidad='" + disponibilidad + "' where id=" + idEquipo.ToString();
	objSentencia->ExecuteNonQuery();
	cerrarConexion();
}