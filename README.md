# drive-name

Native implementation that retrieves drive volume name for a given drive mount point.
Currently supports Windows only.

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
    drives.foreach(drive => {
        drive.mountpoints.foreach(mountpoint => console.log(mountpoint.path, getDriveName(mountpoint.path)));
    });
});
```

</br><hr>
**Author:** Benny Megidish.