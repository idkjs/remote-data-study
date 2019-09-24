type route =
  | RandomOnly
  | Home
  | NotFound;

let routeToPath = route =>
  switch (route) {
  | RandomOnly => "random"
  | Home => "home"
  | _ => ""
  };

let routeToUrl = route =>
  switch (route) {
  | RandomOnly => "/random"
  | Home => "/home"
  | _ => "/"
  };

let useAppUrl = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["random"] => RandomOnly
  | ["home"]
  | [] => Home
  | _ => NotFound
  };
};