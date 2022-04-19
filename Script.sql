/*
CREATE TABLE `db_producto`.`productos` (
  `idPorducto` INT NOT NULL AUTO_INCREMENT,
  `producto` VARCHAR(50) NOT NULL,
  `idMarca` SMALLINT NOT NULL,
  `Descripcion` VARCHAR(100) NOT NULL,
  `precio_costo` DECIMAL(8,2) NOT NULL,
  `precio_venta` DECIMAL(8,2) NOT NULL,
  `existencia` INT NOT NULL,
  `fecha_ingreso` DATETIME NOT NULL,
  `Productoscol` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idPorducto`));
  
  CREATE TABLE `db_producto`.`marcas` (
  `idMarca` SMALLINT NOT NULL AUTO_INCREMENT,
  `marca` VARCHAR(50) NOT NULL,
  PRIMARY KEY (`idMarca`),
  UNIQUE INDEX `marca_UNIQUE` (`marca` ASC) VISIBLE);
  
  ALTER TABLE `db_producto`.`productos` 
ADD INDEX ` id_marca_producto_producto_idx` (`idMarca` ASC) VISIBLE;
;
ALTER TABLE `db_producto`.`productos` 
ADD CONSTRAINT ` id_marca_producto_producto`
  FOREIGN KEY (`idMarca`)
  REFERENCES `db_producto`.`marcas` (`idMarca`)
  ON DELETE NO ACTION
  ON UPDATE CASCADE;
  
  */