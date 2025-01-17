USE [mchavez]
GO
/****** Object:  Table [dbo].[citaMedica]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[citaMedica](
	[idCita] [int] IDENTITY(1,1) NOT NULL,
	[idMedico] [int] NULL,
	[idPaciente] [int] NULL,
	[fecha] [varchar](10) NULL,
	[hora] [varchar](5) NULL,
	[proposito] [varchar](200) NULL,
	[resultado] [varchar](200) NULL,
 CONSTRAINT [PK_CitaMedica] PRIMARY KEY CLUSTERED 
(
	[idCita] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[equipoMedico]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[equipoMedico](
	[idEquipo] [int] IDENTITY(1,1) NOT NULL,
	[nombre] [varchar](50) NULL,
	[disponibilidad] [varchar](50) NULL,
 CONSTRAINT [PK_EquipoMedico] PRIMARY KEY CLUSTERED 
(
	[idEquipo] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[especialidad]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[especialidad](
	[idEspecialidad] [int] IDENTITY(1,1) NOT NULL,
	[nombre] [varchar](200) NULL,
 CONSTRAINT [PK_Especialidad] PRIMARY KEY CLUSTERED 
(
	[idEspecialidad] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[historialMedico]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[historialMedico](
	[idHistorial] [int] IDENTITY(1,1) NOT NULL,
	[idPaciente] [int] NULL,
	[idTratamientoProgramado] [int] NULL,
 CONSTRAINT [PK_HistorialMedico] PRIMARY KEY CLUSTERED 
(
	[idHistorial] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[medico]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[medico](
	[idMedico] [int] IDENTITY(1,1) NOT NULL,
	[idPersona] [int] NOT NULL,
	[numeroColegioMedico] [varchar](20) NULL,
	[certificaciones] [text] NULL,
PRIMARY KEY CLUSTERED 
(
	[idMedico] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[medico_especialidad]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[medico_especialidad](
	[idMedico] [int] NOT NULL,
	[idEspecialidad] [int] NOT NULL,
 CONSTRAINT [PK_medico_especialidad] PRIMARY KEY CLUSTERED 
(
	[idMedico] ASC,
	[idEspecialidad] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[medico_paciente]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[medico_paciente](
	[idMedicoPaciente] [int] IDENTITY(1,1) NOT NULL,
	[idMedico] [int] NULL,
	[idPaciente] [int] NULL,
 CONSTRAINT [PK_MedicoxPaciente] PRIMARY KEY CLUSTERED 
(
	[idMedicoPaciente] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[paciente]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[paciente](
	[idPaciente] [int] IDENTITY(1,1) NOT NULL,
	[apellidos] [varchar](30) NULL,
	[nombres] [varchar](30) NULL,
	[fechaNacimiento] [int] NULL,
	[genero] [varchar](10) NULL,
	[direccion] [varchar](100) NULL,
	[telefonos] [varchar](50) NULL,
	[email] [varchar](50) NULL,
	[estadoCivil] [varchar](10) NULL,
	[altura] [float] NULL,
	[tipoDocumento] [varchar](10) NULL,
	[numeroDocumento] [varchar](8) NULL,
	[numeroHistoria] [varchar](8) NULL,
	[numeroSeguro] [varchar](20) NULL,
	[grupoSanguineo] [varchar](25) NULL,
	[contactoEmergencia] [varchar](100) NULL,
	[alergias] [varchar](250) NULL,
	[enfermedadesPreexistentes] [varchar](250) NULL,
PRIMARY KEY CLUSTERED 
(
	[idPaciente] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[persona]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[persona](
	[idPersona] [int] IDENTITY(1,1) NOT NULL,
	[apellidos] [varchar](30) NULL,
	[nombres] [varchar](30) NULL,
	[fechaNacimiento] [int] NULL,
	[genero] [varchar](10) NULL,
	[direccion] [varchar](100) NULL,
	[telefonos] [varchar](50) NULL,
	[email] [varchar](50) NULL,
	[estadoCivil] [varchar](10) NULL,
	[altura] [float] NULL,
	[tipoDocumento] [varchar](10) NULL,
	[numeroDocumento] [varchar](8) NULL,
	[usuario] [varchar](20) NULL,
	[contrasenia] [varchar](20) NULL,
PRIMARY KEY CLUSTERED 
(
	[idPersona] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[procedimiento]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[procedimiento](
	[idProcedimiento] [int] IDENTITY(1,1) NOT NULL,
	[nombre] [varchar](100) NULL,
	[tipo] [varchar](100) NULL,
 CONSTRAINT [PK_Procedimiento] PRIMARY KEY CLUSTERED 
(
	[idProcedimiento] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[procedimiento_equipo]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[procedimiento_equipo](
	[idProcedimientoEquipo] [int] IDENTITY(1,1) NOT NULL,
	[idEquipo] [int] NULL,
	[idProcedimiento] [int] NULL,
 CONSTRAINT [PK_ProcedimientoxEquipoMedico] PRIMARY KEY CLUSTERED 
(
	[idProcedimientoEquipo] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tratamiento]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tratamiento](
	[idTratamiento] [int] IDENTITY(1,1) NOT NULL,
	[estado] [varchar](20) NULL,
	[descripcion] [varchar](100) NULL,
	[idMedico] [int] NULL,
 CONSTRAINT [PK_Tratamiento] PRIMARY KEY CLUSTERED 
(
	[idTratamiento] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tratamiento_procedimiento]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tratamiento_procedimiento](
	[idTratamientoProcedimiento] [int] IDENTITY(1,1) NOT NULL,
	[idTratamiento] [int] NULL,
	[idProcedimiento] [int] NULL,
 CONSTRAINT [PK_TratamientoxProcedimiento] PRIMARY KEY CLUSTERED 
(
	[idTratamientoProcedimiento] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[tratamientoProgramado]    Script Date: 03/12/2024 18:45:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[tratamientoProgramado](
	[idTratamientoProgramado] [int] IDENTITY(1,1) NOT NULL,
	[idCita] [int] NULL,
	[idTratamiento] [int] NULL,
	[fecha] [varchar](10) NULL,
	[hora] [varchar](5) NULL,
	[resultado] [varchar](200) NULL,
 CONSTRAINT [PK_TratamientoProgramado] PRIMARY KEY CLUSTERED 
(
	[idTratamientoProgramado] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[citaMedica] ON 

INSERT [dbo].[citaMedica] ([idCita], [idMedico], [idPaciente], [fecha], [hora], [proposito], [resultado]) VALUES (1, 2, 2, N'03/12/2024', N'09:00', NULL, NULL)
INSERT [dbo].[citaMedica] ([idCita], [idMedico], [idPaciente], [fecha], [hora], [proposito], [resultado]) VALUES (2, 2, 1, N'03/12/2024', N'09:30', NULL, NULL)
SET IDENTITY_INSERT [dbo].[citaMedica] OFF
GO
SET IDENTITY_INSERT [dbo].[equipoMedico] ON 

INSERT [dbo].[equipoMedico] ([idEquipo], [nombre], [disponibilidad]) VALUES (1, N'Equipo 1', N'Disponible')
INSERT [dbo].[equipoMedico] ([idEquipo], [nombre], [disponibilidad]) VALUES (2, N'Equipo 2', N'Disponible')
INSERT [dbo].[equipoMedico] ([idEquipo], [nombre], [disponibilidad]) VALUES (3, N'Equipo 3', N'Disponible')
SET IDENTITY_INSERT [dbo].[equipoMedico] OFF
GO
SET IDENTITY_INSERT [dbo].[medico] ON 

INSERT [dbo].[medico] ([idMedico], [idPersona], [numeroColegioMedico], [certificaciones]) VALUES (1, 2, N'53349', N'Certificado 1,Certificado 2')
INSERT [dbo].[medico] ([idMedico], [idPersona], [numeroColegioMedico], [certificaciones]) VALUES (2, 3, N'87356', N'Certigficado A')
SET IDENTITY_INSERT [dbo].[medico] OFF
GO
INSERT [dbo].[medico_especialidad] ([idMedico], [idEspecialidad]) VALUES (1, 6)
INSERT [dbo].[medico_especialidad] ([idMedico], [idEspecialidad]) VALUES (2, 10)
GO
SET IDENTITY_INSERT [dbo].[paciente] ON 

INSERT [dbo].[paciente] ([idPaciente], [apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [numeroHistoria], [numeroSeguro], [grupoSanguineo], [contactoEmergencia], [alergias], [enfermedadesPreexistentes]) VALUES (1, N'Perez Hurtado', N'Jose', 20001102, N'M', N'Av. Universitaria 1598', N'982648852', N'JosePH@pucp.pe', N'S', 1.6, N'DNI', N'79641358', N'4', N'789652', N'O+', N'987321654', N'penicilina', N'covid')
INSERT [dbo].[paciente] ([idPaciente], [apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [numeroHistoria], [numeroSeguro], [grupoSanguineo], [contactoEmergencia], [alergias], [enfermedadesPreexistentes]) VALUES (2, N'Perez Guerra', N'Tunche', 19970812, N'M', N'Av. Urubamba 1598', N'999955558', N'Tunche@pucp.pe', N'C', 2.3, N'DNI', N'72589631', N'8', N'123456', N'O-', N'985296462', N'dexametasona', N'diabetes')
SET IDENTITY_INSERT [dbo].[paciente] OFF
GO
SET IDENTITY_INSERT [dbo].[persona] ON 

INSERT [dbo].[persona] ([idPersona], [apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [usuario], [contrasenia]) VALUES (1, N'Chávez Castro', N'Manuel', 19900724, N'M', N'Av. Universitaria 1532', N'987654321', N'mhchavez@pucp.pe', N'C', 1.7, N'DNI', N'07630411', N'admin', N'admin')
INSERT [dbo].[persona] ([idPersona], [apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [usuario], [contrasenia]) VALUES (2, N'Garay N.', N'Fanny', 19910924, N'Femenino', N'Jr. Manuel Candamo 123', N'977455321', N'fanny.garay@pucp.pe', N'Casado', 1.65, N'DNI', N'25794477', NULL, NULL)
INSERT [dbo].[persona] ([idPersona], [apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [usuario], [contrasenia]) VALUES (3, N'Peres', N'David', 19981128, N'Masculino', N'Universitaria', N'987456321', N'dfavid@pucp.pe', N'Soltero', 1.7, N'DNI', N'78945617', NULL, NULL)
INSERT [dbo].[persona] ([idPersona], [apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [usuario], [contrasenia]) VALUES (4, N'Chávez Castro', N'Manuel', 19900724, N'M', N'Av. Universitaria 1532', N'987654321', N'mhchavez@pucp.pe', N'C', 1.7, N'DNI', N'07630411', N'admi', N'admi')
SET IDENTITY_INSERT [dbo].[persona] OFF
GO
ALTER TABLE [dbo].[citaMedica]  WITH CHECK ADD  CONSTRAINT [FK_CitaMedica_Medico] FOREIGN KEY([idMedico])
REFERENCES [dbo].[medico] ([idMedico])
GO
ALTER TABLE [dbo].[citaMedica] CHECK CONSTRAINT [FK_CitaMedica_Medico]
GO
ALTER TABLE [dbo].[citaMedica]  WITH CHECK ADD  CONSTRAINT [FK_CitaMedica_Paciente] FOREIGN KEY([idPaciente])
REFERENCES [dbo].[paciente] ([idPaciente])
GO
ALTER TABLE [dbo].[citaMedica] CHECK CONSTRAINT [FK_CitaMedica_Paciente]
GO
ALTER TABLE [dbo].[historialMedico]  WITH CHECK ADD  CONSTRAINT [FK_Historial_Paciente] FOREIGN KEY([idPaciente])
REFERENCES [dbo].[paciente] ([idPaciente])
GO
ALTER TABLE [dbo].[historialMedico] CHECK CONSTRAINT [FK_Historial_Paciente]
GO
ALTER TABLE [dbo].[historialMedico]  WITH CHECK ADD  CONSTRAINT [FK_TratamientoProgramado_HistorialMedico] FOREIGN KEY([idTratamientoProgramado])
REFERENCES [dbo].[tratamientoProgramado] ([idTratamientoProgramado])
GO
ALTER TABLE [dbo].[historialMedico] CHECK CONSTRAINT [FK_TratamientoProgramado_HistorialMedico]
GO
ALTER TABLE [dbo].[medico]  WITH CHECK ADD  CONSTRAINT [FK_Medico_Paciente] FOREIGN KEY([idPersona])
REFERENCES [dbo].[persona] ([idPersona])
GO
ALTER TABLE [dbo].[medico] CHECK CONSTRAINT [FK_Medico_Paciente]
GO
ALTER TABLE [dbo].[medico_especialidad]  WITH CHECK ADD  CONSTRAINT [FK_medico_especialidad_medico_especialidad] FOREIGN KEY([idMedico], [idEspecialidad])
REFERENCES [dbo].[medico_especialidad] ([idMedico], [idEspecialidad])
GO
ALTER TABLE [dbo].[medico_especialidad] CHECK CONSTRAINT [FK_medico_especialidad_medico_especialidad]
GO
ALTER TABLE [dbo].[medico_especialidad]  WITH CHECK ADD  CONSTRAINT [FK_Medico_EspecialidadMedico] FOREIGN KEY([idMedico])
REFERENCES [dbo].[medico] ([idMedico])
GO
ALTER TABLE [dbo].[medico_especialidad] CHECK CONSTRAINT [FK_Medico_EspecialidadMedico]
GO
ALTER TABLE [dbo].[medico_paciente]  WITH CHECK ADD  CONSTRAINT [FK_MedicoPaciente_Medico] FOREIGN KEY([idMedico])
REFERENCES [dbo].[medico] ([idMedico])
GO
ALTER TABLE [dbo].[medico_paciente] CHECK CONSTRAINT [FK_MedicoPaciente_Medico]
GO
ALTER TABLE [dbo].[medico_paciente]  WITH CHECK ADD  CONSTRAINT [FK_MedicoPaciente_Paciente] FOREIGN KEY([idPaciente])
REFERENCES [dbo].[paciente] ([idPaciente])
GO
ALTER TABLE [dbo].[medico_paciente] CHECK CONSTRAINT [FK_MedicoPaciente_Paciente]
GO
ALTER TABLE [dbo].[procedimiento_equipo]  WITH CHECK ADD  CONSTRAINT [FK_EquipoMedico_EquipoMedicoProcedimiento] FOREIGN KEY([idEquipo])
REFERENCES [dbo].[equipoMedico] ([idEquipo])
GO
ALTER TABLE [dbo].[procedimiento_equipo] CHECK CONSTRAINT [FK_EquipoMedico_EquipoMedicoProcedimiento]
GO
ALTER TABLE [dbo].[procedimiento_equipo]  WITH CHECK ADD  CONSTRAINT [FK_Procedimiento_EquipoProcedimiento] FOREIGN KEY([idProcedimiento])
REFERENCES [dbo].[procedimiento] ([idProcedimiento])
GO
ALTER TABLE [dbo].[procedimiento_equipo] CHECK CONSTRAINT [FK_Procedimiento_EquipoProcedimiento]
GO
ALTER TABLE [dbo].[tratamiento]  WITH CHECK ADD  CONSTRAINT [FK_Tratamiento_Medico] FOREIGN KEY([idMedico])
REFERENCES [dbo].[medico] ([idMedico])
GO
ALTER TABLE [dbo].[tratamiento] CHECK CONSTRAINT [FK_Tratamiento_Medico]
GO
ALTER TABLE [dbo].[tratamiento_procedimiento]  WITH CHECK ADD  CONSTRAINT [FK_Procedimiento_TratamientoProcedimiento] FOREIGN KEY([idProcedimiento])
REFERENCES [dbo].[procedimiento] ([idProcedimiento])
GO
ALTER TABLE [dbo].[tratamiento_procedimiento] CHECK CONSTRAINT [FK_Procedimiento_TratamientoProcedimiento]
GO
ALTER TABLE [dbo].[tratamiento_procedimiento]  WITH CHECK ADD  CONSTRAINT [FK_Tratamiento_TratamientoProcedimiento] FOREIGN KEY([idTratamiento])
REFERENCES [dbo].[tratamiento] ([idTratamiento])
GO
ALTER TABLE [dbo].[tratamiento_procedimiento] CHECK CONSTRAINT [FK_Tratamiento_TratamientoProcedimiento]
GO
ALTER TABLE [dbo].[tratamientoProgramado]  WITH CHECK ADD  CONSTRAINT [FK_TratamientoProgramado_Cita] FOREIGN KEY([idCita])
REFERENCES [dbo].[citaMedica] ([idCita])
GO
ALTER TABLE [dbo].[tratamientoProgramado] CHECK CONSTRAINT [FK_TratamientoProgramado_Cita]
GO
ALTER TABLE [dbo].[tratamientoProgramado]  WITH CHECK ADD  CONSTRAINT [FK_TratamientoProgramado_Tratamiento] FOREIGN KEY([idTratamiento])
REFERENCES [dbo].[tratamiento] ([idTratamiento])
GO
ALTER TABLE [dbo].[tratamientoProgramado] CHECK CONSTRAINT [FK_TratamientoProgramado_Tratamiento]
GO
