// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.bs.js");

function shouldPreventDefault(e) {
  if (e.metaKey) {
    return false;
  } else {
    return !e.ctrlKey;
  }
}

function RouterLink(Props) {
  var href = Props.href;
  var className = Props.className;
  var children = Props.children;
  var handleClick = function ($$event) {
    if (!$$event.defaultPrevented && shouldPreventDefault($$event)) {
      $$event.preventDefault();
      return ReasonReactRouter.push(href);
    }
    
  };
  var tmp = {
    href: href,
    onClick: handleClick
  };
  if (className !== undefined) {
    tmp.className = Caml_option.valFromOption(className);
  }
  return React.createElement("a", tmp, children);
}

var make = RouterLink;

exports.shouldPreventDefault = shouldPreventDefault;
exports.make = make;
/* react Not a pure module */
