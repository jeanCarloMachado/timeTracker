SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

DROP SCHEMA IF EXISTS ;
CREATE SCHEMA IF NOT EXISTS DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci ;
USE ;

-- -----------------------------------------------------
-- Table `activities`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `activities` ;

CREATE  TABLE IF NOT EXISTS `activities` (
  `name` VARCHAR(45) NOT NULL ,
  `description` VARCHAR(500) NULL ,
  `minutes` INT NULL ,
  PRIMARY KEY (`name`) )
;


-- -----------------------------------------------------
-- Table `project`
DROP TABLE IF EXISTS `project` ;

CREATE  TABLE IF NOT EXISTS `project` (
  `name` VARCHAR(45) NOT NULL ,
  `activities_name` VARCHAR(45) NOT NULL ,
  `description` VARCHAR(500) NULL ,
  `sdate` DATE NULL ,
  `fdate` DATE NULL ,
  `hours` INT NULL ,
  PRIMARY KEY (`name`, `activities_name`) ,
  CONSTRAINT `fk_project_activities`
    FOREIGN KEY (`activities_name` )
    REFERENCES `activities` (`name` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
;


-- -----------------------------------------------------
-- Table `categories`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `categories` ;

CREATE  TABLE IF NOT EXISTS `categories` (
  `name` VARCHAR(45) NOT NULL ,
  `description` VARCHAR(500) NULL ,
  PRIMARY KEY (`name`) )
;


-- -----------------------------------------------------
-- Table `goals`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `goals` ;

CREATE  TABLE IF NOT EXISTS `goals` (
  `name` VARCHAR(45) NOT NULL ,
  `description` VARCHAR(500) NULL ,
  `categories_name` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`name`, `categories_name`) ,
  CONSTRAINT `fk_goals_categories1`
    FOREIGN KEY (`categories_name` )
    REFERENCES `categories` (`name` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
;


-- -----------------------------------------------------
-- Table `reminder`
-- -----------------------------------------------------
DROP TABLE IF EXISTS `reminder` ;

CREATE  TABLE IF NOT EXISTS `reminder` (
  `name` VARCHAR(45) NOT NULL ,
  `description` VARCHAR(500) NULL ,
  PRIMARY KEY (`name`) )
;



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
