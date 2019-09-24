/*
from RemoteData's type t passing actual words of the opaque types
type t('data, 'pending, 'error) =
  | NotAsked
  | Loading('pending)
  | Failure('error)
  | Success('data); */
type t('data) = RemoteData.t('data, option('data), string);

type apiAction('data) =
  | RequestLoading
  | RequestError(string)
  | RequestSuccess('data);

// let toLoading = (data: t('data)) =>
//   RemoteData.(Loading(data |> map(d => Some(d)) |> withDefault(None)));
let toLoading = (data: t('data)): t('data) =>
  RemoteData.(Loading(data |> map(d => Some(d)) |> withDefault(None)));

let updateWebData = (data: t('data), action: apiAction('data)): t('data) => {
  switch (action) {
  | RequestLoading => data |> toLoading
  | RequestError(error) => RemoteData.Failure(error)
  | RequestSuccess(response) => RemoteData.Success(response)
  };
};