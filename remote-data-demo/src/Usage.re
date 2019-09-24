type data = list(string);
type error = string;
type remoteData = RemoteData.t(data, data, error);

let debugLog = (v: remoteData) =>
  switch (v) {
  | RemoteData.NotAsked => "Not Asked"
  | Loading(previous) =>
    let s = Js.Array.joinWith(", ", previous->Belt.List.toArray);
    {j|Loading ($s)|j};
  | Success(data) =>
    let s = Js.Array.joinWith(" + ", data->Belt.List.toArray);
    {j|Success ($s)|j};
  | Failure(_error) => "Failure"
  };

Js.log(RemoteData.NotAsked->debugLog);
Js.log(RemoteData.NotAsked->debugLog);
/* output: Not Asked */

Js.log(RemoteData.Loading(["foo", "bar"])->debugLog);
/* output: Loading (foo, bar)*/

Js.log(RemoteData.Success(["foo", "bar", "baz"])->debugLog);
/* output: Success (foo + bar + baz)*/

Js.log(RemoteData.Failure("oops")->debugLog);