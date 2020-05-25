
"use strict";

let MobileData = require('./MobileData.js');
let MissionHotpointTask = require('./MissionHotpointTask.js');
let MissionWaypointTask = require('./MissionWaypointTask.js');
let VOPosition = require('./VOPosition.js');
let FlightAnomaly = require('./FlightAnomaly.js');
let MissionWaypointAction = require('./MissionWaypointAction.js');
let Waypoint = require('./Waypoint.js');
let Gimbal = require('./Gimbal.js');
let MissionWaypoint = require('./MissionWaypoint.js');
let WaypointList = require('./WaypointList.js');

module.exports = {
  MobileData: MobileData,
  MissionHotpointTask: MissionHotpointTask,
  MissionWaypointTask: MissionWaypointTask,
  VOPosition: VOPosition,
  FlightAnomaly: FlightAnomaly,
  MissionWaypointAction: MissionWaypointAction,
  Waypoint: Waypoint,
  Gimbal: Gimbal,
  MissionWaypoint: MissionWaypoint,
  WaypointList: WaypointList,
};
