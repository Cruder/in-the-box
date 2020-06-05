component Main {
  connect Stores.Notifications exposing { notifications, add, delete }

  style base {
  }

  fun notificationDoorOpened : Promise(Never, Void) {
    add({description = "Door Opened", emitedAt = Time.now()})
  }

  fun notificationDoorClosed : Promise(Never, Void) {
    add({description = "Door Closed", emitedAt = Time.now()})
  }

  fun notificationMailRemoved : Promise(Never, Void) {
    add({description = "Mail Removed", emitedAt = Time.now()})
  }

  fun notificationMailAdded : Promise(Never, Void) {
    add({description = "Mail Added", emitedAt = Time.now()})
  }

  fun render : Html {
    <Layout>
      <Notifications />

      <button onClick={notificationDoorOpened}>
        "Door Opened"
      </button>

      <button onClick={notificationDoorClosed}>
        "Door Closed"
      </button>

      <button onClick={notificationMailRemoved}>
        "Mail Removed"
      </button>

      <button onClick={notificationMailAdded}>
        "Mail Added"
      </button>
    </Layout>
  }
}
