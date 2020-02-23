const driveName = require('../drive_name');

async function getDriveNameTest(driveMountPoint) {
  console.log();
  console.log('getDriveName() Test:');
  console.log();
  console.log(`Drive: '${driveMountPoint}' Name: '${driveName.getDriveName(driveMountPoint)}'`);
}

// run tests
getDriveNameTest('D://');
getDriveNameTest('E://');

