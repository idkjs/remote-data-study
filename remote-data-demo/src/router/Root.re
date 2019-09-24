module NotLoading = {
  [@react.component]
  let make = () => {
    <h1> {React.string("So sorry...")} </h1>;
  };
};
[@react.component]
let make = () => {
  let route = Routing.useAppUrl();

  let activePage =
    React.useMemo1(
      () =>
        switch (route) {
        | Home => <AdviceApp />
        | RandomOnly => <RandomOnly />
        | NotFound => <NotLoading />
        },
      [|route|],
    );
  <>
    <header>
      <RouterLink href={Routing.routeToUrl(Home)} className="nav-link">
        {React.string("Home")}
      </RouterLink>
      <RouterLink href={Routing.routeToUrl(RandomOnly)} className="nav-link">
        {React.string("RandomOnly")}
      </RouterLink>
    </header>
    <main> activePage </main>
  </>;
};