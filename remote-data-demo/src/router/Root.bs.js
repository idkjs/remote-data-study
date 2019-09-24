// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Routing$ReactHooksTemplate = require("./Routing.bs.js");
var AdviceApp$ReactHooksTemplate = require("../AdviceApp.bs.js");
var RandomOnly$ReactHooksTemplate = require("../RandomOnly.bs.js");
var RouterLink$ReactHooksTemplate = require("./RouterLink.bs.js");

function Root$NotLoading(Props) {
  return React.createElement("h1", undefined, "So sorry...");
}

var NotLoading = {
  make: Root$NotLoading
};

function Root(Props) {
  var route = Routing$ReactHooksTemplate.useAppUrl(/* () */0);
  var activePage = React.useMemo((function () {
          switch (route) {
            case /* RandomOnly */0 :
                return React.createElement(RandomOnly$ReactHooksTemplate.make, { });
            case /* Home */1 :
                return React.createElement(AdviceApp$ReactHooksTemplate.make, { });
            case /* NotFound */2 :
                return React.createElement(Root$NotLoading, { });
            
          }
        }), /* array */[route]);
  return React.createElement(React.Fragment, undefined, React.createElement("header", undefined, React.createElement(RouterLink$ReactHooksTemplate.make, {
                      href: Routing$ReactHooksTemplate.routeToUrl(/* Home */1),
                      className: "nav-link",
                      children: "Home"
                    }), React.createElement(RouterLink$ReactHooksTemplate.make, {
                      href: Routing$ReactHooksTemplate.routeToUrl(/* RandomOnly */0),
                      className: "nav-link",
                      children: "RandomOnly"
                    })), React.createElement("main", undefined, activePage));
}

var make = Root;

exports.NotLoading = NotLoading;
exports.make = make;
/* react Not a pure module */
