component Main {
  connect Stores.Notifications exposing { notifications, add, delete }

  style page {
    background: #fcdc59;
    text-align: center;
    height: flex;
  }

  style h1 {
    background: #5c14c4;
    text-align: center;
    color:white;
    font-size:30px;
    padding:20px;
  }

  style button {
      background-color: #4CAF50;
      border: none;
      color: white;
      padding: 15px 32px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
      margin: 4px 2px;
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
    <div::page>
      
      <div::h1>
        "In The Box"
      </div>
      
      <Notifications />

      <button::button onClick={notificationDoorOpened}>
        "Door Opened"
      </button>

      <button::button onClick={notificationDoorClosed}>
        "Door Closed"
      </button>

      <button::button onClick={notificationMailRemoved}>
        "Mail Removed"
      </button>

      <button::button onClick={notificationMailAdded}>
        "Mail Added"
      </button>
      
    </div>
  }
}
