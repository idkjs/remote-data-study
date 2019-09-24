type t('data, 'pending, 'error) =
  | NotAsked
  | Loading('pending)
  | Failure('error)
  | Success('data);

let andMap: (t('data, 'pending, 'error), t('data => 'b, 'pending, 'error)) => t('b, 'pending, 'error);

let map: ('data => 'b, t('data, 'pending, 'error)) => t('b, 'pending, 'error);

let map2: (('data, 'b) => 'c, t('data, 'pending, 'error), t('b, 'pending, 'error)) => t('c, 'pending, 'error);

let map3:
  (('data, 'b, 'c) => 'd, t('data, 'pending, 'error), t('b, 'pending, 'error), t('c, 'pending, 'error)) =>
  t('d, 'pending, 'error);

let mapError: ('error => 'f, t('data, 'pending, 'error)) => t('data, 'pending, 'f);

let mapBoth: ('data => 'b, 'error => 'f, t('data, 'pending, 'error)) => t('b, 'pending, 'f);

let andThen: ('data => t('data, 'pending, 'error), t('data, 'pending, 'error)) => t('data, 'pending, 'error);

let withDefault: ('data, t('data, 'pending, 'error)) => 'data;

let fromResult: Belt.Result.t('data, 'error) => t('data, 'pending, 'error);

let toOption: t('data, 'pending, 'error) => option('data);

let append: (t('data, 'pending, 'error), t('b, 'pending, 'error)) => t(('data, 'b), 'pending, 'error);

let succeed: 'data => t('data, 'pending, 'error);

let isSuccess: t('data, 'pending, 'error) => bool;

let isFailure: t('data, 'pending, 'error) => bool;

let isLoading: t('data, 'pending, 'error) => bool;

let isNotAsked: t('data, 'pending, 'error) => bool;
