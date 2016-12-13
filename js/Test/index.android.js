import React, { Component } from 'react';
import {
    AppRegistry,
    View,
    Text,
    StyleSheet,
    TouchableHighlight,
    TouchableOpacity,
    TouchableNativeFeedback,
} from 'react-native';


class NativeButton extends Component {
    constructor(props) {
        super(props);
    }

    _onPressButton() {

    }

    render() {
        return (
            <TouchableNativeFeedback
                onPress={this._onPressButton}
                background={TouchableNativeFeedback.SelectableBackground()}>
                <View style={[styles.bigblue]}>
                    <Text style={{margin: 45}}>Button</Text>
                </View>
            </TouchableNativeFeedback>
        );

    }
}


class OpacityButton extends Component {
    constructor(props) {
        super(props);
    }

    _onPressButton() {
    }

    render() {
        return (
            <TouchableOpacity
             onPress={this._onPressButton}
             background={TouchableNativeFeedback.SelectableBackgroundBorderless()}>
                <View style={[styles.bigblue]}>
                    <Text style={{margin: 45}}>Button</Text>
                </View>
            </TouchableOpacity>
        );

    }
}

class Test extends Component {
    render() {
        return (
            <View>
                <NativeButton />
                <NativeButton />
                <OpacityButton />
                <OpacityButton />
            </View>
        );
    }
}


const styles = StyleSheet.create({
    bigblue: {
        backgroundColor: 'steelblue',
        width: 150,
        height: 100,
    },
    smallred: {
        color: 'red',
        fontSize: 10,
    },
    midgreen: {
        color: 'green',
        fontWeight: 'bold',
        fontSize: 15,
    },
});

AppRegistry.registerComponent('Test', () => Test);
