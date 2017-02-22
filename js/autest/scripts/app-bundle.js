define('app',["exports"], function (exports) {
    "use strict";

    Object.defineProperty(exports, "__esModule", {
        value: true
    });

    function _classCallCheck(instance, Constructor) {
        if (!(instance instanceof Constructor)) {
            throw new TypeError("Cannot call a class as a function");
        }
    }

    var App = exports.App = function () {
        function App() {
            _classCallCheck(this, App);

            this.total = [];
            this.types = [new Type(), new Type(), new Type(), new Type()];
            this.types[0].name = "Halla";
            this.types[1].name = "Yoyo";
            this.types[2].name = "balle";
            this.types[3].name = "gnaribuss";
        }

        App.prototype.addType = function addType() {
            this.types.push(new Type());
        };

        App.prototype.clickHandler = function clickHandler(type) {
            this.total.push({ entryName: type.name, entryHours: type.hours });
        };

        return App;
    }();

    var Type = function Type() {
        _classCallCheck(this, Type);

        this.name = "placeholder";
        this.hours = 120;
    };
});
define('environment',["exports"], function (exports) {
  "use strict";

  Object.defineProperty(exports, "__esModule", {
    value: true
  });
  exports.default = {
    debug: true,
    testing: true
  };
});
define('main',['exports', './environment'], function (exports, _environment) {
  'use strict';

  Object.defineProperty(exports, "__esModule", {
    value: true
  });
  exports.configure = configure;

  var _environment2 = _interopRequireDefault(_environment);

  function _interopRequireDefault(obj) {
    return obj && obj.__esModule ? obj : {
      default: obj
    };
  }

  Promise.config({
    warnings: {
      wForgottenReturn: false
    }
  });

  function configure(aurelia) {
    aurelia.use.standardConfiguration().feature('resources');

    if (_environment2.default.debug) {
      aurelia.use.developmentLogging();
    }

    if (_environment2.default.testing) {
      aurelia.use.plugin('aurelia-testing');
    }

    aurelia.start().then(function () {
      return aurelia.setRoot();
    });
  }
});
define('resources/index',["exports"], function (exports) {
  "use strict";

  Object.defineProperty(exports, "__esModule", {
    value: true
  });
  exports.configure = configure;
  function configure(config) {}
});
define('text!app.html', ['module'], function(module) { module.exports = "<template><require from=\"bootstrap/dist/css/bootstrap.css\"></require><div class=\"container-fluid\"><button repeat.for=\"type of types\" click.trigger=\"clickHandler(type)\" class=\"btn btn-lg btn-info col-xs-6 col-md-4 col-lg-2\">${type.name}</button> <button click.trigger=\"addType()\" class=\"btn btn-lg btn-info col-xs-6 glyphicon glyphicon-plus\"></button></div></template>"; });
//# sourceMappingURL=app-bundle.js.map