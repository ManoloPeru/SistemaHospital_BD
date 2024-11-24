USE [lpoo_2024_2]
GO
/****** Object:  Table [dbo].[persona]    Script Date: 22/10/2024 18:25:51 ******/
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
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO

insert into persona values ('Chávez Castro', 'Manuel', 19900724, 'M', 'Av. Universitaria 1532', '987654321', 'mhchavez@pucp.pe', 'C', 1.70, 'DNI', '07630411', 'admin', 'admin');