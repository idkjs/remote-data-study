// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");

function Spinner(Props) {
  var match = Props.show;
  var show = match !== undefined ? match : false;
  return React.createElement("div", {
              className: "spinner-container"
            }, show ? React.createElement("div", {
                    className: "spinner"
                  }) : null);
}

var make = Spinner;

exports.make = make;
/* react Not a pure module */
