const os = require('os');
const driveNameModule = require('bindings')('drive_name.node');

module.exports = {
  getDriveName(driveMountPoint) {
    const platform = os.platform();

    switch (platform) {
      case 'win32':
      case 'darwin':
      case 'linux':
        return driveNameModule.getDriveName(driveMountPoint);
      default:
        throw new Error(`platform '${platform}' is currently unsupported by drive-name.`);
    }
  }
};
