# drive-name

Native implementation that retrieves drive volume name for a given drive mount point.
Currently supports Windows only.

[![licence](https://img.shields.io/github/license/bennymeg/drive-name.svg)](https://github.com/bennymeg/drive-name/blob/master/LICENSE)
[![npm version](https://img.shields.io/npm/v/drive-name.svg)](https://www.npmjs.com/package/drive-name)
[![Dependencies status](https://david-dm.org/bennymeg/drive-name/status.svg)](https://david-dm.org/bennymeg/drive-name)

## Usage
```js
import { getDriveName } from 'drive-name';

console.log(getDriveName('C://'));
```

This module works great in conjunction with [drivelist](https://github.com/balena-io-modules/drivelist):
```js
import * as drivelist from 'drivelist';
import { getDriveName } from 'drive-name';

// print all the drives and their names respectively
drivelist.list().then(drives => {
    drives.forEach(drive => {
        drive.mountpoints.forEach(mountpoint => console.log(mountpoint.path, getDriveName(mountpoint.path)));
    });
});
```

</br><hr>
**Author:** Benny Megidish.