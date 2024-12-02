CREATE TABLE [dbo].[EquipoMedico](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[nombre] [varchar](50) NULL,
	[disponibilidad] [varchar](50) NULL,
	CONSTRAINT [PK_EquipoMedico] PRIMARY KEY CLUSTERED ([id] ASC)
);

CREATE TABLE [dbo].[medico](
	[idMedico] [int] IDENTITY(1,1) NOT NULL,
	[idPersona] [int] NOT NULL,
	[numeroColegioMedico] [varchar](20) NULL,
	[certificaciones] [text] NULL,
PRIMARY KEY CLUSTERED 
([idMedico] ASC)
);

CREATE TABLE [dbo].[medico_especialidad](
	[idMedico] [int] NOT NULL,
	[idEspecialidad] [int] NOT NULL,
 CONSTRAINT [PK_medico_especialidad] PRIMARY KEY CLUSTERED ([idMedico] ASC,	[idEspecialidad] ASC)
);

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
PRIMARY KEY CLUSTERED (	[idPersona] ASC)
);

ALTER TABLE [dbo].[medico]  WITH CHECK ADD  CONSTRAINT [FK_Medico_Paciente] FOREIGN KEY([idPersona])
REFERENCES [dbo].[persona] ([idPersona]);

ALTER TABLE [dbo].[medico] CHECK CONSTRAINT [FK_Medico_Paciente];

ALTER TABLE [dbo].[medico_especialidad]  WITH CHECK ADD  CONSTRAINT [FK_medico_especialidad_medico_especialidad] FOREIGN KEY([idMedico], [idEspecialidad])
REFERENCES [dbo].[medico_especialidad] ([idMedico], [idEspecialidad]);

ALTER TABLE [dbo].[medico_especialidad] CHECK CONSTRAINT [FK_medico_especialidad_medico_especialidad];


INSERT [dbo].[persona] ([apellidos], [nombres], [fechaNacimiento], [genero], [direccion], [telefonos], [email], [estadoCivil], [altura], [tipoDocumento], [numeroDocumento], [usuario], [contrasenia]) 
VALUES ('Chávez Castro', 'Manuel', 19900724, 'M', 'Av. Universitaria 1532', '987654321', 'mhchavez@pucp.pe', 'C', 1.7, 'DNI', '07630411', 'admi', 'admi');
