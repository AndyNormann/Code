export class App {
    constructor() {
        this.total = [];
        this.types = [
            new Type(),
            new Type(),
            new Type(),
            new Type()
        ];
        this.types[0].name = "Halla";
        this.types[1].name = "Yoyo";
        this.types[2].name = "balle";
        this.types[3].name = "gnaribuss";
    }

    addType() {
        this.types.push(new Type());
    }

    clickHandler(type) {
        this.total.push({entryName: type.name, entryHours: type.hours});
    }
}

class Type {
    constructor() {
        this.name = "placeholder";
        this.hours = 120;
    }
}
