#pragma once
namespace SistemaHospitalController {
	using namespace System;
	using namespace System::Data::SqlClient;

	public ref class BaseController {
	private:
		SqlConnection^ objConexion; /*Es el atributo que va a ayudarnos a establecer la conexion con la BD*/

	public:
		BaseController();
		SqlConnection^ getObjConexion();
		void abrirConexion();
		void cerrarConexion();
	};
}