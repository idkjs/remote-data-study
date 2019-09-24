// // type webData('a) = RemoteData.t('a, 'a, string);
// type webData('a, 'p, 'e) =
//   | NotAsked
//   | Loading('p)
//   | Failure('e)
//   | Success('a);

// type advice = {
//   id: string,
//   value: string,
// };
// type searchResponse = {
//   total_results: int,
//   items: array(advice),
// };
// type state = {
//   searchResult: RemoteData.t(searchResponse, option(searchResponse), string),
// };
// // type state = {searchResult: webData(searchResponse)};
// type action =
//   | SearchLoading
//   | SearchError(string)
//   | SearchSuccess(searchResponse);

// let initialState = {searchResult: RemoteData.NotAsked};

// let reducer = (state, action) =>
//   switch (action) {
//   | SearchLoading => {
//       searchResult:
//         RemoteData.(
//           Loading(
//             state.searchResult
//             |> map(data => Some(data))
//             |> withDefault(None),
//           )
//         ),
//     }
//   | SearchSuccess(result) => {
//       searchResult: RemoteData.Success(result),
//     }
//   | SearchError(error) => {
//       searchResult: RemoteData.Failure(error),
//     }
//   };

// let fetchRandom = dispatch => {
//   dispatch(SearchLoading);
//   Js.Promise.(
//     Api.fetchRandomAdvice()
//     |> then_(result =>
//          switch (result) {
//          | Belt.Result.Ok(response) =>
//            dispatch(SearchSuccess(response))
//            |> resolve
//          | Belt.Result.Error () =>
//            dispatch(
//                SearchError("An error occured! Please, try again."),
//            )
//            |> resolve
//          }
//        )
//   );
// };
// let handleClick = _event => Js.log("clicked!");

// /* `make` is the function that mandatorily takes `children` (if you want to use
//    `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

//    `<Component1 message="hello" />`

//    Which desugars to

//    `React.createElement(
//      Component1.make,
//      Component1.makeProps(~message="hello", ())
//    )` */
// [@react.component]
// let make = (~message) => {
//   let (state, dispatch) = React.useReducer(reducer, initialState);

//   let randomAdvice =
//     Api.fetchRandomAdvice()
//     |> Js.Promise.then_(res => Js.log(res) |> Js.Promise.resolve);
//   Js.log2("randomAdvice", randomAdvice);
//   <div onClick=handleClick>
//     {ReasonReact.string(message)}
//     {ReasonReact.string(randomAdvice)}
//   </div>;
// };