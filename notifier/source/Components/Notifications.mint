component Notification {
  property notification : Notification

  fun render : Html {
    <div>
      <p><{notification.description}></p>
      <p>"Created at #{Time.format("yyyy-MM-dd hh:mm:ss", notification.emitedAt)}"</p>
    </div>
  }
}

component Notifications {
  connect Stores.Notifications exposing { notifications }

  fun render : Html {
    <>
      for (notification of notifications) {
        <Notification notification={notification}/>
      }
    </>
  }
}