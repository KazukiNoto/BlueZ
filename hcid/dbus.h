/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2004-2006  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __H_BLUEZ_DBUS_H__
#define __H_BLUEZ_DBUS_H__

#include <dbus/dbus.h>
#include "dbus-adapter.h"

DBusMessage *dev_signal_factory(const int devid, const char *prop_name, const int first, ...);

DBusMessage *new_authentication_return(DBusMessage *msg, uint8_t status);

int get_default_dev_id(void);

void create_bond_req_exit(const char *name, struct adapter *adapter);
void discover_devices_req_exit(const char *name, struct adapter *adapter);
int cancel_discovery(struct adapter *adapter);
void periodic_discover_req_exit(const char *name, struct adapter *adapter);
int cancel_periodic_discovery(struct adapter *adapter);

int active_conn_find_by_bdaddr(const void *data, const void *user_data);
void bonding_request_free(struct bonding_request_info *dev);
int pin_req_cmp(const void *p1, const void *p2);
int found_device_cmp(const struct remote_dev_info *d1,
			const struct remote_dev_info *d2);
int found_device_add(struct slist **list, bdaddr_t *bdaddr, int8_t rssi,
			name_status_t name_status);
int found_device_req_name(struct adapter *dbus_data);

int discov_timeout_handler(void *data);

#endif /* __H_BLUEZ_DBUS_H__ */
