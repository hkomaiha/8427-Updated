/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>
#include "ctre/Phoenix.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
#include <frc/GenericHID.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
// #include <VictorSPX.h>

using namespace frc;

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private: 
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  frc::XboxController controller{0};
  
  WPI_VictorSPX sr1{21};
  WPI_VictorSPX sr2{20};
  WPI_VictorSPX sr3{11};  
  WPI_VictorSPX sr4{10};


  WPI_VictorSPX Arm{30};
  WPI_VictorSPX intakeMotor{31};

  frc::Timer timer;

  

// WPI_TalonSRX sr1a = {0};
// WPI_TalonSRX sr2a = {0};
// WPI_TalonSRX sr3a = {0};  
// WPI_TalonSRX sr4a = {0};

   frc::SpeedControllerGroup right {sr1, sr2};
   frc::SpeedControllerGroup left {sr3,sr4};
  frc::DifferentialDrive drivetrain{left,right};
 
};
