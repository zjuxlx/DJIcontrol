
"use strict";

let MissionStatus = require('./MissionStatus.js')
let MissionHpResetYaw = require('./MissionHpResetYaw.js')
let QueryDroneVersion = require('./QueryDroneVersion.js')
let SetLocalPosRef = require('./SetLocalPosRef.js')
let MissionWpUpload = require('./MissionWpUpload.js')
let MFIOConfig = require('./MFIOConfig.js')
let Stereo240pSubscription = require('./Stereo240pSubscription.js')
let MissionHpUpdateYawRate = require('./MissionHpUpdateYawRate.js')
let MissionWpGetSpeed = require('./MissionWpGetSpeed.js')
let MissionHpGetInfo = require('./MissionHpGetInfo.js')
let DroneTaskControl = require('./DroneTaskControl.js')
let SetHardSync = require('./SetHardSync.js')
let SendMobileData = require('./SendMobileData.js')
let MissionWpAction = require('./MissionWpAction.js')
let StereoDepthSubscription = require('./StereoDepthSubscription.js')
let MissionHpAction = require('./MissionHpAction.js')
let CameraAction = require('./CameraAction.js')
let DroneArmControl = require('./DroneArmControl.js')
let StereoVGASubscription = require('./StereoVGASubscription.js')
let MFIOSetValue = require('./MFIOSetValue.js')
let MissionHpUpload = require('./MissionHpUpload.js')
let SetupCameraStream = require('./SetupCameraStream.js')
let Activation = require('./Activation.js')
let MissionWpGetInfo = require('./MissionWpGetInfo.js')
let MissionHpUpdateRadius = require('./MissionHpUpdateRadius.js')
let MissionWpSetSpeed = require('./MissionWpSetSpeed.js')
let SDKControlAuthority = require('./SDKControlAuthority.js')

module.exports = {
  MissionStatus: MissionStatus,
  MissionHpResetYaw: MissionHpResetYaw,
  QueryDroneVersion: QueryDroneVersion,
  SetLocalPosRef: SetLocalPosRef,
  MissionWpUpload: MissionWpUpload,
  MFIOConfig: MFIOConfig,
  Stereo240pSubscription: Stereo240pSubscription,
  MissionHpUpdateYawRate: MissionHpUpdateYawRate,
  MissionWpGetSpeed: MissionWpGetSpeed,
  MissionHpGetInfo: MissionHpGetInfo,
  DroneTaskControl: DroneTaskControl,
  SetHardSync: SetHardSync,
  SendMobileData: SendMobileData,
  MissionWpAction: MissionWpAction,
  StereoDepthSubscription: StereoDepthSubscription,
  MissionHpAction: MissionHpAction,
  CameraAction: CameraAction,
  DroneArmControl: DroneArmControl,
  StereoVGASubscription: StereoVGASubscription,
  MFIOSetValue: MFIOSetValue,
  MissionHpUpload: MissionHpUpload,
  SetupCameraStream: SetupCameraStream,
  Activation: Activation,
  MissionWpGetInfo: MissionWpGetInfo,
  MissionHpUpdateRadius: MissionHpUpdateRadius,
  MissionWpSetSpeed: MissionWpSetSpeed,
  SDKControlAuthority: SDKControlAuthority,
};
