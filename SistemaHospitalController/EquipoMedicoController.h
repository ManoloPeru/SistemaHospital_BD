#pragma once

namespace SistemaHospitalController {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace SistemaHospitalModel;

	public ref class EquipoMedicoController {
	public:
		EquipoMedicoController();
		List<EquipoMedico^>^ listarEquipoMedico();
		List<ReporteEquipoMedico^>^ contarCantidadEquipos();
	};
}