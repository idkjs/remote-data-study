include Types;
// reusable component
[@react.component]
let make = (~text, ~type_) => {
  let className =
    switch (type_) {
    | Information => "message--info"
    | Error => "message--error"
    };

  <div className> {React.string(text)} </div>;
};
