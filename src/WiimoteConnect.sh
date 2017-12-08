#!/bin/bash

bluez-simple-agent hci0 8C:56:C5:3F:DF:62
bluez-test-device trusted 8C:56:C5:3F:DF:62 yes
bluez-test-input connect 8C:56:C5:3F:DF:62
