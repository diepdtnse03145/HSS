import QtQuick 2.5
import QtQuick.Window 2.0
import QtQuick.Controls 1.2

import VPlayPlugins.parse 1.1


ApplicationWindow {
    visible: true
    width: 1080
    height: 1920
    Parse {
        licenseKey: "1802219D9DB5B476BA12870EB3692921CF8F51009303CD091C54CAE8FB75266744F0903190C1645BF5EF5BCE6FDCAFA47AAC14A439DCC9184F386EF532B78AFE94A1FF80B56F577E4CFA9785CA3B97359A0646B65AD510425377A94FD104A7E62D4F2417C60AE77152331FACFBEE0DAD57D39D948AD94D8A7AA8D064594D167F2C1ED80450248E441E231BED59E19782988A68BE40DEA9510D2EC40E82DF4804"

        applicationId: "jd37VwBvjVLm9z1vdnE6zKrSkAi0u7XMCKHQgZrp"
        clientKey: "hrvSbRN7lgP6c1ZD0i32DilLDRanpTy9G3dy6B1P"

        //    channels: [ "channel-1" ]

        onNotificationReceived: {
            console.debug("Received notification", JSON.stringify(data))

        }
    }

}
