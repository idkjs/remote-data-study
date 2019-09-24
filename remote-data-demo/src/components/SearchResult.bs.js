// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var Message$ReactHooksTemplate = require("./Message.bs.js");

function SearchResult(Props) {
  var data = Props.data;
  var items = data[/* items */1];
  if (items.length !== 0) {
    return React.createElement("ol", {
                className: "search-result-list"
              }, $$Array.map((function (item) {
                      return React.createElement("li", {
                                  key: item[/* id */0],
                                  className: "search-result-item"
                                }, item[/* value */1]);
                    }), items));
  } else {
    return React.createElement(Message$ReactHooksTemplate.make, {
                text: "Ooops... No advice found!",
                type_: /* Information */0
              });
  }
}

var make = SearchResult;

exports.make = make;
/* react Not a pure module */
