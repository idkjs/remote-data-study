open Api;
open Types;

// type randomResponse = {item: advice};

/* define a type for our remote data response. Since WebData is a polymorphic type it can take some value. So here we are defining that value as Types.advice which is ```type advice = {
  id: string,
  value: string,
};```  */
type remoteRandomAdvice = WebData.t(advice);

/* Define our state as having an identifier of randomAdvice of the type remoteRandomAdvice that we just defined. This means we have access to all of the identifies on that type which will allow us to use them to update our ui */
type state = {
  randomAdvice: remoteRandomAdvice,
};

/*
This is then WebData.re apiAction type.
 type apiAction('a) =
  | RequestLoading
  | RequestError(string)
  | RequestSuccess('a); */
type action =
  | RandomAdviceRequest(WebData.apiAction(advice));

let reducer = (state, action) => {
  switch (action) {
  | RandomAdviceRequest(randomAction) => {
      randomAdvice: WebData.updateWebData(state.randomAdvice, randomAction),
    }
  };
};

let initialState = {randomAdvice: RemoteData.NotAsked};

let fetchRandom = dispatch => {
  dispatch(RandomAdviceRequest(RequestLoading));
  Js.Promise.(
    fetchRandomAdvice()
    |> then_(result =>
         switch (result) {
         | Belt.Result.Ok(response) =>
           dispatch(RandomAdviceRequest(RequestSuccess(response.item)))
           |> resolve
         | Belt.Result.Error () =>
           dispatch(
             RandomAdviceRequest(
               RequestError("An error occured! Please, try again."),
             ),
           )
           |> resolve
         }
       )
  );
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  React.useEffect0(() => {
    fetchRandom(dispatch) |> ignore;
    None;
  });

  let handleRandomClick = _ => {
    fetchRandom(dispatch) |> ignore;
  };

  <>
    <div className="background" />
    <div className="content">
      <div className="panel">
        <h2 className="title"> {ReasonReact.string("Ask for advice")} </h2>
      </div>
      <div className="delimiter" />
      <div className="panel">
        <button
          onClick=handleRandomClick
          disabled={RemoteData.isLoading(state.randomAdvice)}>
          {ReasonReact.string("Refresh")}
        </button>
        <h2 className="title title--small">
          {ReasonReact.string("Random wisdom:")}
        </h2>
        {switch (state.randomAdvice) {
         | NotAsked => ReasonReact.null
         | Success(data) => <RandomAdvice data />
         | Loading(result) =>
           <>
             <div className="loader" />
             {result
              ->Belt.Option.flatMap(data => Some(<RandomAdvice data />))
              ->Belt.Option.getWithDefault(ReasonReact.null)}
           </>
         | Failure(err) => <div> {ReasonReact.string(err)} </div>
         }}
      </div>
    </div>
  </>;
};