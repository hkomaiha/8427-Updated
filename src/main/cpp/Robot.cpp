/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"


using namespace frc;


void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  
}

/*
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
 
  timer.Start();

  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
 // std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
}
}
void Robot::AutonomousPeriodic() {
//std::cout << timer.Get() << std:: endl;
if (double(timer.Get()) <= 1.5) {
  drivetrain.ArcadeDrive (.7,0.0);
}
else if ((double(timer.Get()) > 1.55) && (double(timer.Get()) < 2.05)) {
  drivetrain.ArcadeDrive (0,-.55,0);
}
else if ((double(timer.Get()) > 2.05) && (double(timer.Get()) < 3.55)) {
  drivetrain.ArcadeDrive (.77,0.0); 
}
else if ((double(timer.Get()) > 3.55 && (double(timer.Get()) < 4.05))) {
  drivetrain.ArcadeDrive (0,.45,0);
}
else if ((double(timer.Get()) > 4.05 && (double(timer.Get()) < 4.75))) {
  drivetrain.ArcadeDrive (.7,0,0);
}
//else if (timer.Get() > 4.75 and timer.Get() < 5.25){
 // drivetrain.ArcacdeDrive (0,.45,0);
//}
//else if (timer.Get() > 5.25 and timer.Get() < 5.95){
// // drivetrain.ArcadeDrive (-7,0,0);
//}
else {
 drivetrain.ArcadeDrive (0,0,0);
}
}


//Relay *exampleRelay = new Relay(1);
//Relay *exampleRelay = new Relay(1, Relay::Value::kForward)
//exampleRelay->Set(Relay::Value::kOn);
//exampleRelay->Set(Relay::Value::kForward


// intakeMotor.Set(ControlMode::PercentOutput, 0.5);



// Wait(2.0);

 //if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  //}else{}
    // Default Auto goes here
//}

void Robot::TeleopInit(){};

void Robot::TeleopPeriodic() {
//  sr1.Set(ControlMode::PercentOutput, -.1);
//  sr2.Set(ControlMode::PercentOutput, -.1);
//  sr3.Set(ControlMode::PercentOutput, .1);
//  sr4.Set(ControlMode::PercentOutput, .1);

  if (controller.GetLeftTriggerAxis()){
  intakeMotor.Set(ControlMode::PercentOutput, -10.0);

  }else if (controller.GetRightTriggerAxis()){
   intakeMotor.Set(ControlMode::PercentOutput, 7.0);

  }else {
   intakeMotor.Set(ControlMode::PercentOutput, 0.0);
   
  }


  
// double yLoc = controller.GetRightY()* 0.7;
// double xLoc = controller.GetRightX()* 0.7;
drivetrain.ArcadeDrive((controller.GetLeftY()* -0.7), (controller.GetRightX()* 0.7));
// drivetrain.ArcadeDrive((controller.GetRightX()/2), (controller.GetRightX()));

// std::cout << "Controller y:" << yLoc << "\n";
// std::cout << "Controller x:" << xLoc << "\n";
// std::cout<< controller.GetRightY()<<std:: endl;
// std::cout<< controller.GetRightX()<<std::endl;
if (controller.GetLeftBumper()){
  Arm.Set(ControlMode::PercentOutput, -1);
}else if (controller.GetRightBumper()){
  Arm.Set(ControlMode::PercentOutput, 1);
}else{
  Arm.Set(ControlMode::PercentOutput, 0);
}
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif