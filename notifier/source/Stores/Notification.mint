store Stores.Notifications {
  state notifications = [] of Notification

  fun add(notification : Notification) {
    next { notifications = Array.push(notification, notifications) }
  }

  fun delete(notification : Notification) {
    next { notifications = Array.delete(notification, notifications) }
  }
}
