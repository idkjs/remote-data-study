// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Axios = require("axios");
var Caml_format = require("bs-platform/lib/js/caml_format.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");

function decodeAdvice(json) {
  return /* record */[
          /* id */Json_decode.field("slip_id", Json_decode.string, json),
          /* value */Json_decode.field("advice", Json_decode.string, json)
        ];
}

function decodeSearchResult(json) {
  return /* record */[
          /* total_results */Caml_format.caml_int_of_string(Json_decode.field("total_results", Json_decode.string, json)),
          /* items */Json_decode.field("slips", (function (param) {
                  return Json_decode.array(decodeAdvice, param);
                }), json)
        ];
}

function decodeRandomResponse(json) {
  return /* record */[/* item */Json_decode.field("slip", decodeAdvice, json)];
}

function decodeMessage(json) {
  return /* record */[/* type_ */Json_decode.at(/* :: */[
                  "message",
                  /* :: */[
                    "type",
                    /* [] */0
                  ]
                ], Json_decode.string)(json)];
}

function messageToResponse(message) {
  var match = message[/* type_ */0];
  if (match === "notice") {
    return /* Ok */Block.__(0, [/* record */[
                /* total_results */0,
                /* items : array */[]
              ]]);
  } else {
    return /* Error */Block.__(1, [/* () */0]);
  }
}

var apiBaseUrl = "https://api.adviceslip.com/advice";

function searchAdvice(query) {
  return Axios.get(apiBaseUrl + ("/search/" + query)).then((function (response) {
                  var searchResult;
                  try {
                    searchResult = decodeSearchResult(response.data);
                  }
                  catch (exn){
                    var exit = 0;
                    var message;
                    try {
                      message = decodeMessage(response.data);
                      exit = 2;
                    }
                    catch (exn$1){
                      return Promise.resolve(/* Error */Block.__(1, [/* () */0]));
                    }
                    if (exit === 2) {
                      return Promise.resolve(messageToResponse(message));
                    }
                    
                  }
                  return Promise.resolve(/* Ok */Block.__(0, [searchResult]));
                })).catch((function (param) {
                return Promise.resolve(/* Error */Block.__(1, [/* () */0]));
              }));
}

function fetchRandomAdvice(param) {
  return Axios.get(apiBaseUrl).then((function (response) {
                  return Promise.resolve(/* Ok */Block.__(0, [decodeRandomResponse(response.data)]));
                })).catch((function (param) {
                return Promise.resolve(/* Error */Block.__(1, [/* () */0]));
              }));
}

exports.decodeAdvice = decodeAdvice;
exports.decodeSearchResult = decodeSearchResult;
exports.decodeRandomResponse = decodeRandomResponse;
exports.decodeMessage = decodeMessage;
exports.messageToResponse = messageToResponse;
exports.apiBaseUrl = apiBaseUrl;
exports.searchAdvice = searchAdvice;
exports.fetchRandomAdvice = fetchRandomAdvice;
/* axios Not a pure module */