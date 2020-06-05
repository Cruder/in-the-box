component Layout {
  property children : Array(Html) = []

  style base {
  }

  style content {
  }

  fun render : Html {
    <div::base>
      <Header/>

      <div::content>
        <{ children }>
      </div>

      <Footer/>
    </div>
  }
}
