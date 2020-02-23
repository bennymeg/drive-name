const driveName = require('../drive_name');
const driveList = require('drivelist');

async function getDriveNameTest(driveMountPoint) {
  console.log();
  console.log('getDriveName() Test:');
  console.log();
  console.log(`Drive: '${driveMountPoint}' Name: '${driveName.getDriveName(driveMountPoint)}'`);
}

async function getAllDriveNameTest() {
  console.log();
  console.log('getAllDriveName() Test:');
  console.log();

  // print all the drives and their names respectively
  driveList.list().then(drives => {
    drives.forEach(drive => {
        drive.mountpoints.forEach(mountpoint => {
          console.log(`Drive: '${mountpoint.path}' Name: '${driveName.getDriveName(mountpoint.path)}'`);
        });
    });
  });
}

// run tests
getDriveNameTest('D://');
getDriveNameTest('E://');
getAllDriveNameTest();
